// StackOverRun.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

void foo(const char* input)
{
    char buf[10];

    // 次のprinfに渡す引数は不足しているが、
    // これはスタックの内容を表示sる為の簡単なトリックである
    // このトリックは、書式指定文字列について検討する特に再び使用する
    printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n\n");

    // セキュアなプログラムに直接ユーザー入力を渡す
    strcpy(buf, input);
    printf("%s\n", buf);
    printf("Now the stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n\n");

}

//これが攻撃用のコード
void var(void)
{
    printf("Augh I've been hacked!\n");
}

int main(int argc, char* argv[])
{
    // 状況をわかりやすく示すためにアドレスを表示する
    printf("Address of foo = %p\n", foo);
    printf("Address of var = %p\n", var);
    if (argc != 2)
    {
        printf("Please supply a string as an argument!\n");
        return -1;
    }
    foo(argv[1]);
    return 0;
}

