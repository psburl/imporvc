for test_file in $(find test -type f | grep -e "test_.*\.c")
do 
    bin_name=$(echo $test_file | sed 's/test\///' | sed 's/\.c//')
    gcc $test_file -o bin/$bin_name
    domain=$(echo $bin_name | sed 's/test_//')
    echo "testing ${domain} functions ..."
    ./bin/$bin_name
done