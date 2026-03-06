# Paper Airplane Judge ✈️

O programa executa vários testes para verificar se a solução do problema **Aviões de papel** está correta.
Link do problema: https://olimpiada.ic.unicamp.br/pratique/pj/2009/f1/papel/

---

# 📂 Estrutura do projeto

```
project/
│
├─ judge.exe
├─ judge.cpp
├─ planeExample.cpp
│
└─ papel/
   ├─ test1/
   │  ├─ in1
   │  └─ out1
   ├─ test2/
   │  ├─ in1
   │  └─ out1
   └─ ...
```

* **judge.exe** → programa que executa os testes
* **planeExample.cpp** → exemplo de como o código deve ser estruturado
* **papel/** → pasta contendo todos os casos de teste

---

# ⚙️ Pré-requisitos

Antes de executar o verificador, é necessário ter o compilador **g++** instalado no sistema.

---

# 🧑‍💻 Como usar

Siga os passos abaixo:

### 1️⃣ Coloque seu código na pasta do projeto

O usuário deve colocar seu arquivo:

```
plane.cpp
```

na pasta principal do projeto.

Se necessário, utilize o arquivo:

```
planeExample.cpp
```

como referência de como a solução deve ser estruturada.

---

### 2️⃣ Execute o verificador

Execute o arquivo:

```
judge.exe
```

O programa irá:

1. Compilar `plane.cpp`
2. Executar todos os testes dentro da pasta `papel`
3. Comparar a saída do programa com os gabaritos

---

# 📊 Resultado

Ao final da execução, o programa mostrará algo como:

```
test1: OK
test2: OK
test3: FALHOU

=====================
Total de testes: 10
Acertos: 9
Erros: 1
Pontuação: 90%
=====================
```

---

# 📌 Observação

* Cada pasta dentro de `papel` contém:

  * **in1** → entrada do teste
  * **out1** → saída esperada

O `judge.exe` executa seu programa utilizando `in1` e compara o resultado com `out1`.

---

# 🎯 Objetivo

O objetivo do projeto é simular um **juiz automático de programação**, semelhante aos usados em plataformas de competição e aprendizado de algoritmos.
