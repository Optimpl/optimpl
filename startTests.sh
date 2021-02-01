echo "This program will start tests"


echo "Checking if the test executeable exists..."

if test -f build/optimpl ; then
    if ./build/optimpl ; then
        echo "Tests successful"
    else
        echo "One or more tests were failed"
    fi
else
    echo "Fatal: No executable found! Did you forget to build the tests?"
fi