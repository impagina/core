#!/bin/bash

if [[ $# == 0 ]]; then
  echo "usage: $0 ClassName"
  echo "usage: $0 LibraryName SubClassName"
  exit;
fi

nameClass=${1^}
echo $nameClass
libraryClass=${1^}
if [[ $# > 1 ]]; then
  nameClass=$libraryClass${2^}
fi

libraryConstant=${libraryClass^^} # all uppercase
libraryFile=${libraryClass,} # lowercase first
nameConstant=${nameClass^^} # all uppercase
nameFile=${nameClass,} # lowercase first
fileH=$nameFile".h"
fileCPP=$nameFile".cpp"

#echo $nameClass
#echo $fileH
#echo $fileCPP

if [ -e $fileH ]; then
  echo $fileH "already exists."
else
  cat > $fileH <<EOL
#ifndef ${nameConstant}_H
#define ${nameConstant}_H

#include "${libraryFile}_global.h"

class ${libraryConstant}SHARED_EXPORT ${nameClass}
{
public:
    ${nameClass}();
};

#endif // ${nameConstant}_H
EOL
    echo "add $fileH to your project"
fi

if [ -e $fileCPP ]; then
  echo $fileCPP "already exists."
else
  cat > $fileCPP <<EOL
#include "${fileH}"

${nameClass}::${nameClass}()
{
}
EOL
    echo "add $fileCPP to your project"
fi

