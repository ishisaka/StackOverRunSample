// StackOverRun.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

void foo(const char* input)
{
    char buf[10];

    // ����prinf�ɓn�������͕s�����Ă��邪�A
    // ����̓X�^�b�N�̓��e��\��s��ׂ̊ȒP�ȃg���b�N�ł���
    // ���̃g���b�N�́A�����w�蕶����ɂ��Č���������ɍĂюg�p����
    printf("My stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n\n");

    // �Z�L���A�ȃv���O�����ɒ��ڃ��[�U�[���͂�n��
    strcpy(buf, input);
    printf("%s\n", buf);
    printf("Now the stack looks like:\n%p\n%p\n%p\n%p\n%p\n%p\n\n");

}

//���ꂪ�U���p�̃R�[�h
void var(void)
{
    printf("Augh I've been hacked!\n");
}

int main(int argc, char* argv[])
{
    // �󋵂��킩��₷���������߂ɃA�h���X��\������
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

