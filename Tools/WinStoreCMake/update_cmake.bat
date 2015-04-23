@echo off
set WORK_DIR_REPO=cmake_repo
if exist %WORK_DIR_REPO% (
cd %WORK_DIR_REPO%
git pull https://github.com/Microsoft/cmake feature/Win10
git status
cd ..
) else (
git clone https://github.com/Microsoft/cmake %WORK_DIR_REPO%
cd %WORK_DIR_REPO%
git checkout feature/Win10
git status
cd ..
)

