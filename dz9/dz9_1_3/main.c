// Сказка квест
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Vy Il'ya Muromec, vam nadoelo lejat' na pechi i vy otpravilis' za podvigami\n\n");
    printf("Pod'ehali vy k kamnyu u razvilki i prochli: Nalevo poedesh' sebya poteryaesh', napravo poedesh' konya poteryaesh', pryamo poedesh' nejivoi budesh'.\n\n");
    printf("1. nalevo\n2. pryamo\n3. napravo\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("Proehali vy pyatirik shagov da ugodili v volch'yu yamu. A vas ved' preduprejdali :)))");
        break;
    case 2:
        printf("Proehali vy pyatirik shagov da i pomerli. A vas ved' preduprejdali :)))");
        break;
    case 3:
        printf("Proehali vy pyatirik shagov a kon' zdox. A vas ved' preduprejdali :)))");
        break;
    }
    return 0;
}
