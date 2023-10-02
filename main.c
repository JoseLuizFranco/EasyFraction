#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

void resposta(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void respostaln(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

void clearConsole() {
    system("clear");
    system("cls");
    resposta("\e[1;1H\e[2J");
}

void logo() {
    respostaln(" ________                       ________                       _    _                   ");
    respostaln("|_   __  |                     |_   __  |                     / |_ (_)                  ");
    respostaln("  | |_ \\_| ,--.   .--.    _   __ | |_ \\_|_ .--.  ,--.   .---.`| |-'__   .--.   _ .--.   ");
    respostaln("  |  _| _ `'_\\ : ( (`\\]  [ \\ [  ]|  _|  [ `/'`\\]`'_\\ : / /'`\\]| | [  |/ .'`\\ \\[ `.-. |  ");
    respostaln(" _| |__/ |// | |, `'.'.   \\ '/ /_| |_    | |    // | |,| \\__. | |, | || \\__. | | | | |  ");
    respostaln("|________|'-;__/[\\__) )[_] :  /|_____|  [___]   '-;__/'.___.'\\__/[___]'.__.' [___||__] ");
    respostaln("                         \\/__.'                                                           ");
}

int mdc(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mmc(int a, int b) {
    return a * (b / mdc(a, b));
}


void simplificarFracao(int *num, int *den) {
    int divisorComum = mdc(*num, *den);
    *num = *num / divisorComum;
    *den = *den / divisorComum;
}

void multiplicador(int num1, int den1, int num2, int den2) {
    int num = num1 * num2;
    int den = den1 * den2;
    simplificarFracao(&num, &den);
    resposta("A multiplicacao das fracoes %d/%d com %d/%d resultou em: %d/%d", num1, den1, num2, den2, num, den);
}

void divisor(int num1, int den1, int num2, int den2) {
    int num = num1 * den2;
    int den = den1 * num2;
    resposta("A divisao das fracoes %d/%d com %d/%d resultou em: %d/%d", num1, den1, num2, den2, num, den);
}

void minteiro(int num, int den) {
    int inp;
    do {
        resposta("Digite o numero inteiro voce gostaria de multiplicar a fracao por: ");
        scanf("%d", &inp);
    } while (inp - (int) inp != 0);
    resposta("A multiplicacao da fracao %d/%d por %d resultou em: %d/%d", num, den, inp, inp*num, den);
}

void verificarPropria(int num, int den) {
    if (num < den) {
        resposta("A fracao %d/%d é própria", num, den);
    } else {
        resposta("A fracao %d/%d é imprópria", num, den);
    }
}

void inverterFracao(int *num, int *den) {
    int temp = *num;
    if (temp == 0) {
        resposta("Infelizmente nao podemos inverter esta fracao, ja que o denominador dela agora tera valor 0. Escolha outra fracao ou outra opcao.");
        return;
    }
    *num = *den;
    *den = temp;
    resposta("A fracao invertida é: %d/%d", *num, *den);
}

void inverterFracaoImprima(int num, int den) {
    int temp = num;
    if (temp == 0) {
        resposta("Infelizmente nao podemos inverter esta fracao, ja que o denominador dela agora tera valor 0. Escolha outra fracao ou outra opcao.");
        return;
    }
    num = den;
    den = temp;
    resposta("A fracao invertida é: %d/%d", num, den);
}

void adicionarFracoes(int num1, int den1, int num2, int den2) {
    int den = mmc(den1, den2);
    int num = (num1 * (den / den1)) + (num2 * (den / den2));

    resposta("A soma das fracoes é: %d/%d", num, den);
}

void subtrairFracoes(int num1, int den1, int num2, int den2) {
    int den = mmc(den1, den2);
    int num = (num1 * (den / den1)) - (num2 * (den / den2));

    resposta("A subtracao das fracoes é: %d/%d", num, den);
}

void compararFracoes(int num1, int den1, int num2, int den2) {
    float frac1 = (float)num1 / den1;
    float frac2 = (float)num2 / den2;
    if (frac1 > frac2) {
        resposta("A fracao %d/%d é maior que %d/%d", num1, den1, num2, den2);
    } else if (frac1 < frac2) {
        resposta("A fracao %d/%d é menor que %d/%d", num1, den1, num2, den2);
    } else {
        resposta("As fracoes são iguais");
    }
}

void intro(int *num1, int *den1, int *num2, int *den2) {
    int valid = 0;
    float temp;
    do {
        resposta("\nDigite o numerador da primeira fracao: ");
        if(scanf("%f", &temp) != 1 || temp != (int)temp) {
            respostaln("Número inválido! Por favor, insira um número inteiro válido.");
            while(getchar() != '\n');
            continue;
        }
        *num1 = (int)temp;

        resposta("\nDigite o denominador da primeira fracao: ");
        if(scanf("%f", &temp) != 1 || temp != (int)temp || (int)temp == 0) {
            respostaln("Número inválido! O denominador deve ser um número inteiro diferente de zero.");
            while(getchar() != '\n');
            continue;
        }
        *den1 = (int)temp;

        resposta("\nDigite o numerador da segunda fracao: ");
        if(scanf("%f", &temp) != 1 || temp != (int)temp) {
            respostaln("Número inválido! Por favor, insinta um número inteiro válido.");
            while(getchar() != '\n');
            continue;
        }
        *num2 = (int)temp;

        resposta("\nDigite o denominador da segunda fracao: ");
        if(scanf("%f", &temp) != 1 || temp != (int)temp || (int)temp == 0) {
            respostaln("Número inválido! O denominador deve ser um número inteiro diferente de zero.");
            while(getchar() != '\n');
            continue;
        }
        *den2 = (int)temp;

        valid = 1;

    } while (!valid);
    clearConsole();
}



void selector(int *num1, int *den1, int *num2, int *den2) {
    int option, fracao;
    float temp, f;
    do {
        clearConsole();
        logo();
        respostaln("   ┌───────────────────────────────────────────────────────────┐");
        respostaln("   │                    Selecione uma opção                    │");
        respostaln("   ├───────────────────────────────────────────────────────────┤");
        respostaln("   │  1. Multiplicar frações                                   │");
        respostaln("   │  2. Dividir frações                                       │");
        respostaln("   │  3. Multiplicar uma fração por um número inteiro          │");
        respostaln("   │  4. Verificar se uma das frações é própria ou imprópria   │");
        respostaln("   │  5. Inverter uma das frações                              │");
        respostaln("   │  6. Adicionar as duas frações                             │");
        respostaln("   │  7. Subtrair as duas frações                              │");
        respostaln("   │  8. Verificar qual das duas é a maior fração              │");
        respostaln("   │  9. Digitar um novo par de frações                        │");
        respostaln("   │  10. Finalizar                                            │");
        respostaln("   └───────────────────────────────────────────────────────────┘");
        resposta("Digite um valor entre 1 e 10: ");
        if(scanf("%f", &temp) != 1 || temp != (int)temp || (int)temp < 1 || (int)temp > 10) {
            respostaln("Opção inválida! Por favor, insira um número entre 1 e 10. [Aguarde 5 segundos...]");
            sleep(5);
            while(getchar() != '\n');
            continue;
        }
        option = (int)temp;

        switch (option) {
            case 1:

                multiplicador(*num1, *den1, *num2, *den2);
                break;
            case 2:
                divisor(*num1, *den1, *num2, *den2);
                break;
            case 3:
                do {
                    resposta("Digite qual fracao deseja utilizar na multiplicacao (1/2): ");
                    if(scanf("%f", &f) != 1 || f != (int)f || !((int) f == 1 || (int) f == 2)) {
                        respostaln("Número inválido! O denominador deve ser um número inteiro e ser ou 1 ou 2.");
                        while(getchar() != '\n');
                        continue;
                    }
                    fracao = (int) f;
                } while (!(fracao == 1 || fracao == 2));
                if (fracao == 1) minteiro(*num1, *den1);
                else minteiro(*num2, *den2);
                break;
            case 4:
                do {
                    resposta("Digite qual fracao deseja utilizar na verificacao (1/2): ");
                    if(scanf("%f", &f) != 1 || f != (int)f || !((int) f == 1 || (int) f == 2)) {
                        respostaln("Número inválido! O denominador deve ser um número inteiro e ser ou 1 ou 2.");
                        while(getchar() != '\n');
                        continue;
                    }
                    fracao = (int) f;
                } while (!(fracao == 1 || fracao == 2));
                if (fracao == 1) verificarPropria(*num1, *den1);
                else verificarPropria(*num2, *den2);
                break;
            case 5:
                do {
                    resposta("Digite qual fracao deseja inverter (1/2): ");
                    if(scanf("%f", &f) != 1 || f != (int)f || !((int) f == 1 || (int) f == 2)) {
                        respostaln("Número inválido! O denominador deve ser um número inteiro e ser ou 1 ou 2.");
                        while(getchar() != '\n');
                        continue;
                    }
                    fracao = (int) f;
                } while (!(fracao == 1 || fracao == 2));
                if (fracao == 1) inverterFracao(num1, den1);
                else inverterFracao(num2, den2);
                break;
            case 6:
                adicionarFracoes(*num1, *den1, *num2, *den2);
                break;
            case 7:
                subtrairFracoes(*num1, *den1, *num2, *den2);
                break;
            case 8:
                compararFracoes(*num1, *den1, *num2, *den2);
                break;
            case 9:
                intro(num1, den1, num2, den2);
                break;
            case 10:
                respostaln("Finalizado com sucesso!");
                return;
            default:
                respostaln("Opção inválida! Tente novamente.");
        }
        if (option != 10) {
            resposta("\nPressione Enter para continuar...");
            getchar();
            getchar();
        }
    } while (option != 10);
}

int main() {
    int num1, den1, num2, den2;
    logo();
    intro(&num1, &den1, &num2, &den2);
    selector(&num1, &den1, &num2, &den2);
    return 0;
}
