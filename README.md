# 🧠 Jogo da Memória

Jogo da memória desenvolvido em **C++** com **Qt Creator**, contendo interface gráfica, sistema de pontuação com persistência em banco de dados e cartas com efeitos especiais.

> Projeto desenvolvido como trabalho final da disciplina de **Linguagem de Programação II** — Curso de Engenharia de Computação, UFSC.

---

## ✨ Funcionalidades

- 🃏 **Cartas com comportamentos distintos**, através de herança e polimorfismo:
  - **Carta Comum** — pares tradicionais do jogo da memória
  - **Carta Bônus** — concede 3 pontos ao jogador (só pode ser usada uma vez)
  - **Carta Armadilha** — retira 2 pontos do jogador e embaralha cartas
- 🏆 **Sistema de pontuação** com placar
- 💾 **Persistência de dados** via SQLite (histórico de partidas/pontuações)
- 🎵 **Trilha sonora e efeitos sonoros** integrados via recursos Qt (`.qrc`)
- ⚙️ **Tela de configurações**
- 🎉 **Tela de vitória**
- ℹ️ **Diálogo "Sobre"** com informações do jogo

---

## 🛠️ Tecnologias utilizadas

- **C++**
- **Qt Framework** (Widgets, QSqlDatabase/SQLite, QSS para estilização)
- **qmake** como sistema de build

---

## 📁 Estrutura do projeto

```
Jogo-da-Memoria/
├── cards/                  # Imagens das cartas
├── songs/                  # Trilhas sonoras
├── sounds/                 # Efeitos sonoros
├── .github/workflows/      # Automação de build (CI)
├── carta.h / carta.cpp                  # Classe base das cartas
├── cartacomum.h / cartacomum.cpp        # Carta comum
├── cartabonus.h / cartabonus.cpp        # Carta bônus
├── cartaarmadilha.h / cartaarmadilha.cpp# Carta armadilha
├── jogo.h / jogo.cpp                    # Lógica principal do jogo
├── mainwindow.h/.cpp/.ui                # Janela principal
├── placar.h/.cpp/.ui                    # Placar de pontuação
├── pontuacao.h / pontuacao.cpp          # Gerenciamento de pontuação
├── settings.h/.cpp/.ui                  # Tela de configurações
├── victory.h/.cpp/.ui                   # Tela de vitória
├── aboutdialog.h/.cpp/.ui               # Diálogo "Sobre"
├── conexao.h                            # Conexão com o banco de dados
├── funcoes.h / funcoes.cpp              # Funções auxiliares
├── Cards.qrc / Songs.qrc / Sounds.qrc / Foto.qrc  # Recursos Qt
├── MemoryGame.pro                       # Arquivo de projeto (qmake)
└── main.cpp                             # Ponto de entrada
```

---

## 🚀 Como compilar e executar

### Pré-requisitos

- [Qt Creator](https://www.qt.io/download) (com Qt 5 ou 6 instalado)
- Módulo **Qt SQL** com driver SQLite habilitado
- Compilador C++ compatível (GCC, MinGW ou MSVC, dependendo do SO)

### Passo a passo

1. Clone o repositório:
   ```bash
   git clone https://github.com/isisvs42/Jogo-da-Memoria.git
   ```
2. Abra o arquivo `MemoryGame.pro` no Qt Creator.
3. Configure um kit de build (Desktop Qt com o compilador desejado).
4. Clique em **Build** e depois em **Run** (ou `Ctrl+R`).

---

## 🎮 Como jogar

Encontre os pares de cartas iguais virando duas cartas por vez. Fique atento: além das cartas comuns, o tabuleiro contém uma **carta bônu**, que ajuda sua pontuação, e uma **carta armadilha**, que pode atrapalhar sua jogada. Complete o tabuleiro com a maior pontuação possível!

---

## 🎵 Créditos de áudio

As trilhas sonoras (`songs/`) utilizadas neste projeto são de artistas independentes. Os créditos de cada faixa estão listados abaixo, com link para o áudio original no YouTube.

| Arquivo em `songs/` | Faixa | Artista | Ouvir no YouTube |
|---|---|---|---|
| `Butterflies by Tsundere Twintails.mp3` | Butterflies | Tsundere Twintails | [link](https://www.youtube.com/watch?v=11dAGSfNvMI) |
| `Demo Booth by Xploshi.mp3` | Demo Booth | Xploshi | [link](https://www.youtube.com/watch?v=yi9xkK8rZl8) |
| `keep ahold of my eyes by overscorn.mp3` | keep ahold of my eyes | overscorn | [link](https://www.youtube.com/watch?v=LVTjq-mVoGU) |
| `LEASE by Takeshi Abo.mp3` | LEASE | Takeshi Abo | [link](https://www.youtube.com/watch?v=tjlvmb8SGEs) |
| `Sweet Sandy Coasty by SupaBubba.mp3` | Sweet Sandy Coast | SupaBubba | [link](https://www.youtube.com/watch?v=PKMyQxYh5Ug) |
| `ufo shopping by tomcbumpz.mp3` | ufo shopping | tomcbumpz | [link](https://youtu.be/vwM4UUCOW70?si=6LU2oqdoK3oLgJpf) |
| `Tomorrow's Problems, Today by esselfortium.mp3` | Tomorrow's Problems, Today | esselfortium | [link](https://www.youtube.com/watch?v=NwamPstNzm4) |
| `Hoogway - A Place I Love.mp3` | A Place I Love | Hoogway | [link](https://www.youtube.com/watch?v=Qk11o0sS8p8) |

---

## 👩‍💻 Autora

Desenvolvido por **[Ísis](https://github.com/isisvs42)**.
