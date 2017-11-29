#!/bin/bash
cat > README.md <<EOF
# Blog
[雨过。天晴的博客](https://sunsijie.top)
EOF


cat >> README.md <<EOF
# Progress
\`\`\`
EOF
leetcode stat > /tmp/tmpr
sed -i -e 's/^/\t/g' /tmp/tmpr 
cat /tmp/tmpr >> README.md
echo "\`\`\`" >> README.md

cat >> README.md <<EOF
# Accecpted
| 序号 | 题名 | 解答 |
|----- |:----:|:----:|
EOF

find ./Accepted -name '*notac*' -delete

for cpp in `ls Accepted | sort -n`;do
	IFS="." splited=($cpp)
	seqno=${splited[0]}
	filename=${splited[1]//-/ }

    cmd=''
    for x in Of By The To And In From With Without;do
        [ ! -z $cmd ] && cmd+='\|'
        cmd+='\b'"$x"'\b'
    done
    cmd='s/'$cmd'/\l&/g'
        
    filename=$(echo $filename | sed 's/ii\b\|^lfu\b\|\bi$\|\bii$\|\biii$\|\biv$\|^\w\|\b\w/\U&/g' | sed "$cmd")
	echo "|$seqno | [$filename](https://leetcode.com/problems/${splited[1]}) | [My Answer](https://github.com/KKRainbow/LeetCode/blob/master/Accepted/${cpp}) |" >> README.md
done

