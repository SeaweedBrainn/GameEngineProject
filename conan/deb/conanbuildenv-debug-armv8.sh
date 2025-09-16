script_folder="/Users/hemang/VSCodeStuff/GameEngineProject/conan/deb"
echo "echo Restoring environment" > "$script_folder/deactivate_conanbuildenv-debug-armv8.sh"
for v in PATH
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanbuildenv-debug-armv8.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanbuildenv-debug-armv8.sh"
    fi
done


export PATH="/Users/hemang/.conan2/p/cmake4043f173ae163/p/CMake.app/Contents/bin:$PATH"