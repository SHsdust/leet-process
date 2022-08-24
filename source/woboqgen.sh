OUTPUT_DIRECTORY=./woboq
DATA_DIRECTORY=$OUTPUT_DIRECTORY/data
BUILD_DIRECTORY=$PWD
SOURCE_DIRECTORY=$PWD
# VERSION=`git describe --always --tags`
# cmake . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
codebrowser_generator -b $BUILD_DIRECTORY -a -o $OUTPUT_DIRECTORY -p leetcode:$SOURCE_DIRECTORY:0.0.1
codebrowser_indexgenerator $OUTPUT_DIRECTORY
cp -rv /home/emrys/Documents/woboq_codebroswer/data $DATA_DIRECTORY
