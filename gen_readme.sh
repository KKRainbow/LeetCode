#!/bin/bash
cat > README.md <<EOF
# Blog
[雨过。天晴的博客](https://sunsijie.top)

# Accecpted
EOF

for cpp in `ls Accepted`;do
	IFS="." splited=($cpp)
	seqno=${splited[0]}
	filename=${splited[1]//-/ }
	echo "- [$seqno.$filename](https://leetcode.com/problems/${splited[1]})" >> README.md
done

echo "# Progress" >> README.md
leetcode stat >> README.md

cat README.md
