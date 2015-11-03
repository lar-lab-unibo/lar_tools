#!/bin/bash
echo "Copying scripts..."
for FILE in lar_tools_*; do
  #ln -s "$FILE" /usr/local/bin/"${FILE}";
  ln -sf ${PWD}/$FILE /usr/local/bin/${FILE}
  chmod +x /usr/local/bin/${FILE}
done
