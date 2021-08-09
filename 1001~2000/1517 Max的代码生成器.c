#include<stdio.h>
#include<string.h>

char a[20];
int len;
int main()
{
    scanf("%s",a);
    len=strlen(a);
    if(len==4)
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a+b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==8&&a[0]=='S')
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a-b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==8&&a[0]=='M')
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a*b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==6)
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a/b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==3)
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a&b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==2)
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a|b);\n");
        printf("    return 0;\n");
        printf("}");
    }
    if(len==11)
    {
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        printf("    int a,b;\n");
        printf("    scanf(\"%%d%%d\",&a,&b);\n");
        printf("    printf(\"%%d\",a^b);\n");
        printf("    return 0;\n");
        printf("}");
    }
}
