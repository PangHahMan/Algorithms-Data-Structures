/* 
链接：https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A 都分别替换成字母F），其他字符不 变，并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

输入
HELLO WORLD SNHJ
输出
CZGGJ RJMGY NICE
*/

#include <stdio.h>
int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = (c > 'E') ? (c - 5) : (c + 21);
        }
        putchar(c);
    }
    return 0;
}