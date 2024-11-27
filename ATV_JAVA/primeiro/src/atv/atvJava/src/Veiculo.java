public class Veiculo {
    private String placa;
    private String marca;
    private String anoFabricacao;
    private String cor;

    public Veiculo(String placa, String marca, String anoFabricacao, String cor) {
        this.placa = placa;
        this.marca = marca;
        this.anoFabricacao = anoFabricacao;
        this.cor = cor;
    }

    public void alterarCor(String novaCor) {
        this.cor = novaCor;
    }

    public void exibirInformacoes() {
        System.out.println("Placa: " + placa);
        System.out.println("Marca: " + marca);
        System.out.println("Ano de Fabricação: " + anoFabricacao);
        System.out.println("Cor: " + cor);
    }

    public String getPlaca() {
        return placa;
    }
}
