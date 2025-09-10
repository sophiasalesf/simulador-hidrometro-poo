# Simulador de Hidrômetro Analógico

Projeto desenvolvido na disciplina de **Padrões de Projeto (IFPB)**.  
O simulador em C++ representa o funcionamento de um hidrômetro analógico, permitindo simular fluxo de água, presença de ar e acompanhar o registro acumulado em **litros, decilitros e metros cúbicos**.

## Funcionalidades
- Configuração da entrada (bitola, vazão, direção do fluxo, ar presente).
- Medição acumulada em decilitros, litros e metros cúbicos.
- Odômetro de 6 dígitos simulando hidrômetros reais.
- Exibição no terminal (versão simples).
- Exportação de resultados em arquivo `.txt`.

## Estrutura do código
- `Entrada` → Configurações da entrada de água.
- `Medicao` → Acumula volume medido.
- `Hidrometro` → Integra entrada e medição.
- `Display` → Exibe informações no terminal.
- `Saida` → Exporta resultados para `.txt`.
- `Controlador` → Coordena a execução da simulação.

## Como compilar
No PowerShell (Windows, usando MinGW):
```sh
mkdir bin 2>$null
g++ -std=c++14 -I . .\Entrada.cpp .\Medicao.cpp .\Hidrometro.cpp .\Display.cpp .\Controlador.cpp .\Saida.cpp .\main.cpp -o .\bin\simulador.exe
.\bin\simulador.exe
```

## Exemplo de saída no terminal
<img width="683" height="459" alt="image" src="https://github.com/user-attachments/assets/86b4c379-6326-403c-a7dd-3170fb310abf" />

## Desenvolvedora
Sophia Sales (IFPB - Engenharia de Computação) (https://github.com/Sophia7b)  
