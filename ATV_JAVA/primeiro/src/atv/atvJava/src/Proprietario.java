import java.util.ArrayList;
import java.util.List;

public class Proprietario {
    private String nome;
    private String cpf;
    private String telefone;
    private String endereco;
    private List<Veiculo> veiculos;

    public Proprietario(String nome, String cpf, String telefone, String endereco) {
        this.nome = nome;
        this.cpf = cpf;
        this.telefone = telefone;
        this.endereco = endereco;
        this.veiculos = new ArrayList<>();
    }

    public void adicionarVeiculo(Veiculo veiculo) {
        veiculos.add(veiculo);
    }

    public void removerVeiculo(String placa) {
        veiculos.removeIf(veiculo -> veiculo.getPlaca().equals(placa));
    }

    public void listarVeiculos() {
        veiculos.forEach(Veiculo::exibirInformacoes);
    }
}
