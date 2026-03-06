#include <iostream> //entrada e saída no terminal
#include <fstream> //ler e escrever arquivos.
#include <filesystem> //mexer com pastas e arquivos do sistema.
#include <cstdlib> //usar funções do sistema, como: system() para rodar comandos do terminal e remove() para deletar arquivos.

using namespace std;
namespace fs = std::filesystem;

int main() {

    //contadores
    int total = 0;
    int passou = 0;
    int falhou = 0;

    cout << "Compilando plane.cpp...\n";

    if (system("g++ plane.cpp -o plane.exe") != 0) {
        cout << "Erro ao compilar o codigo.\n";
        return 1;
    }

    for (const auto &pasta : fs::directory_iterator("papel")) {

        if (!pasta.is_directory()) continue; //ignorar arquivos que não são pastas

        total++;

        string caminho = pasta.path().string();
        string entrada = caminho + "/in1";
        string saidaEsperada = caminho + "/out1";

        system(("plane.exe < \"" + entrada + "\" > resposta.txt 2>&1").c_str());
        // < envia o arquivo como entrada
        // > salva saída em arquivo resposta.txt
        // 2>&1 redireciona erros para o mesmo arquivo resposta.txt

        ifstream resp("resposta.txt"); //saída do programa
        ifstream gab(saidaEsperada); //gabarito esperado

        if (!resp.is_open() || !gab.is_open()) {
            cout << pasta.path().filename().string() << ": erro ao abrir arquivos\n";
            falhou++;
            continue;
        }

        //ler respostas
        string r, g;
        getline(resp, r);
        getline(gab, g);

        if (r == g) {
            cout << pasta.path().filename().string() << ": OK\n";
            passou++;
        } else {
            cout << pasta.path().filename().string() << ": FALHOU\n";
            falhou++;
        }

        //fechar arquivos
        resp.close();
        gab.close();
    }

    cout << "\n=====================\n";
    cout << "Total de testes: " << total << "\n";
    cout << "Acertos: " << passou << "\n";
    cout << "Erros: " << falhou << "\n";

    double pontuacao = (total > 0) ? (100.0 * passou / total) : 0;

    cout << "Pontuacao: " << pontuacao << "%\n";
    cout << "=====================\n";

    //limpar arquivos temporários
    remove("resposta.txt");
    remove("plane.exe");

    cout << "\nPressione ENTER para sair...";
    cin.ignore();
    cin.get();

    return 0;
}