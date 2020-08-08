// A seguir, são apresentados procedimentos simples de controle do motor de passo
# define  EN  8  // habilitação do motor de passo, baixa ativa
# define  X_DIR  5  // controle de direção do motor de passo do eixo X
# define  Y_DIR  6  // controle de direção do motor de passo do eixo y
# define  Z_DIR  7  // controle de direção do motor de passo do eixo z
# define  X_STP  2  // x -axis stepper control
# define  Y_STP  3  // controle de passo do eixo y
# define  Z_STP  4  // controle de passo do eixo z


/ *
/ / Função: etapa. função: para controlar a direção do motor de passo, o número de etapas.
/ / Parâmetros: dir dir control, dirPin pin DIR correspondente do motor de passo, stepperPin pin step correspondente do motor de passo "step", número do passo do passo sem valor de retorno.
* /


 etapa vazia (dir booleano, byte dirPin, byte stepperPin, etapas int )
{
    digitalWrite (dirPin, dir);
    atraso ( 50 );
    para ( int i = 0 ; i <etapas; i ++)
    {
        digitalWrite (stepperPin, HIGH);
        delayMicroseconds ( 800 );
        digitalWrite (stepperPin, LOW);
        delayMicroseconds ( 800 );
    }
}


void  setup () {    // O motor de passo usado no pino IO é definido para saída
    pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
    pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
    pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
    pinMode (EN, OUTPUT);
    digitalWrite (EN, LOW);
}


void  loop () {
    passo ( falso , X_DIR, X_STP, 200 ); // O motor do eixo X reverte 1 anel, o passo 200 é um círculo.
    etapa ( falso , Y_DIR, Y_STP, 200 ); // o motor do eixo y reverte 1 anel, o passo 200 é um círculo.
    etapa ( falso , Z_DIR, Z_STP, 200 ); // motor do eixo z reverte 1 anel, a etapa 200 é um círculo.
    atraso ( 1000 );
    etapa ( verdadeiro , X_DIR, X_STP, 200 ); // O motor do eixo X avança 1 voltas, o passo 200 é um círculo.
    etapa ( verdadeiro , Y_DIR, Y_STP, 200 ); // o motor do eixo y avança 1 voltas, o passo 200 é um círculo.
    etapa ( verdadeiro , Z_DIR, Z_STP, 200 ); // motor do eixo z avança 1 voltas, o passo 200 é um círculo.
    atraso ( 1000 );
}
