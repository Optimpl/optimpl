echo "This file compiles tests for this library"
echo "Now it's going to compile them in the build directory"

# remove the build directory if exists
if [ -d "build" ]; then
    echo "Build directory already exists. Removing it..."
    rm -rf build
fi

echo "Creating build directory and compiling the test files..."
mkdir build
cd build

if ! cmake ../ ; then
    echo "Fatal: Failed to make build files!"
else
    make
fi