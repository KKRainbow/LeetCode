#!/bin/bash
cat > README.md <<EOF
# Blog
[雨过。天晴的博客](https://sunsijie.top)

# Accecpted
| 序号 | 题名 | 解答 |
|----- |:----:|-----:|
EOF

for cpp in `ls Accepted | sort -n`;do
	IFS="." splited=($cpp)
	seqno=${splited[0]}
	filename=${splited[1]//-/ }
	echo "|$seqno | [$filename](https://leetcode.com/problems/${splited[1]}) | [My Answer](https://github.com/KKRainbow/LeetCode/blob/master/Accepted/${cpp}) |" >> README.md
done

cat >> README.md <<EOF
# Progress
\`\`\`
EOF
leetcode stat > /tmp/tmpr
sed -i -e 's/^/\t/g' /tmp/tmpr 
cat /tmp/tmpr >> README.md
echo "\`\`\`" >> README.md
