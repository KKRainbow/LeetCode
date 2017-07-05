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

cat >> README.md <<EOF
# Progress
\`\`\`
EOF
leetcode stat > /tmp/tmpr
vim /tmp/tmpr -c "normal >G" -c "wq"
cat /tmp/tmpr >> README.md
echo "\`\`\`" >> README.md

cat README.md
