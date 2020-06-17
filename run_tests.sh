for test_file in $(find . -type f | grep -e "test_.*\.c")
do 
    bin_name=$(echo $test_file | awk -F/ '{print $NF}' | sed 's/\.c//')
    gcc $test_file -o bin/$bin_name
    domain=$(echo $bin_name | sed 's/test_//')
    echo -e "\n"
    echo "testing ${domain} functions ..."
    echo "------------------------------"
    ./bin/$bin_name
    echo "------------------------------"
done