#!/usr/bin/env bash
set -euo pipefail

# 用法：
#   1) 在题目目录执行：  ../../scripts/debug_cf.sh
#   2) 或传 main.cpp 路径： ./scripts/debug_cf.sh problems/codeforces/1703B_xxx/main.cpp
# 可选：
#   --run   进入 lldb 后自动 run（默认不 run，方便你先下断点）

AUTO_RUN=0
if [[ "${1:-}" == "--run" ]]; then
  AUTO_RUN=1
  shift
fi

find_repo_root() {
  local p="$PWD"
  while [[ "$p" != "/" ]]; do
    if [[ -f "$p/CMakeLists.txt" ]]; then
      echo "$p"
      return 0
    fi
    p="$(dirname "$p")"
  done
  echo "ERROR: cannot find repo root (CMakeLists.txt)" >&2
  exit 1
}

ROOT="$(find_repo_root)"
BUILD_DIR="$ROOT/build-debug"

PROB_DIR="${1:-$PWD}"
if [[ -f "$PROB_DIR" ]]; then
  PROB_DIR="$(cd "$(dirname "$PROB_DIR")" && pwd)"
else
  PROB_DIR="$(cd "$PROB_DIR" && pwd)"
fi

TARGET="$(basename "$PROB_DIR")"
EXE="$BUILD_DIR/$TARGET"
INFILE="$PROB_DIR/in.txt"

# 1) configure (Debug)
if [[ ! -f "$BUILD_DIR/build.ninja" && ! -f "$BUILD_DIR/Makefile" ]]; then
  echo "[configure] $BUILD_DIR"
  cmake -S "$ROOT" -B "$BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
fi

# 2) build target
echo "[build] $TARGET"
cmake --build "$BUILD_DIR" --target "$TARGET"

if [[ ! -x "$EXE" ]]; then
  echo "ERROR: executable not found: $EXE" >&2
  exit 1
fi

echo "[lldb] $EXE"
cd "$PROB_DIR"

# 3) enter interactive lldb (no auto-run by default)
if [[ -f "$INFILE" ]]; then
  echo "[input] stdin <- $INFILE"
  if [[ $AUTO_RUN -eq 1 ]]; then
    lldb \
      -o "target create \"$EXE\"" \
      -o "settings set target.input-path \"$INFILE\"" \
      -o "run" \
      "$EXE"
  else
    lldb \
      -o "target create \"$EXE\"" \
      -o "settings set target.input-path \"$INFILE\"" \
      "$EXE"
  fi
else
  if [[ $AUTO_RUN -eq 1 ]]; then
    lldb -o "target create \"$EXE\"" -o "run" "$EXE"
  else
    lldb -o "target create \"$EXE\"" "$EXE"
  fi
fi