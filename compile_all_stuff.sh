#!/bin/bash

# Функция для компиляции .cpp файлов в указанной директории
compile_cpp() {
    for file in "$1"/*.cpp; do
        if [ -f "$file" ]; then
            output_file="${file%.cpp}"  # Убираем расширение .cpp для исполняемого файла
            echo "Компиляция $file в $output_file"
            g++ "$file" -o "$output_file"
        fi
    done
}

# Рекурсивно проходим по поддиректориям
find . -type d | while read -r dir; do
    compile_cpp "$dir"
done
 
