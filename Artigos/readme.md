# Tutorial Básico e Rápido 

### Como Instalar as principais Bibliotecas de Computação Gráfica na distro Debian 10 do Linux. 
O primeiro passo é entrar em seu Terminal como Root. Para isso basta digitar “su” , e digitar a sua senha de super usuário.

O próximo passo será instalar a build básica para o funcionamento do GCC.
> apt-get update
> apt-get install build-essential



Agora que a build está instalada, vamos partir para as bibliotecas.

A Primeira | FREEGLUT
> apt-get install freeglut3-dev

A Segunda | GLEW
> apt-get install libglew-dev

A Terceira | SOIL
> apt install libsoil-dev

A Quarta e última | SDL
> apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev

Assim toda a configuração está pronta! Agora para rodar o seu código, você 
deve atentar a qual biblioteca você instanciou no início do arquivo, e digitar no terminal :
> gcc nomeDoArquivo.c(ou cpp) -lGL -lGLU -lglut (-lSOIL se tiver soil)

Última Observação:
Ao contrário do Windows, que quando se utiliza da IDE CodeBlocks se deve chamar o SOIL manualmente nas configurações para cada aplicação, nessa distro Linux é só fazer o passo a passo acima, o que facilita muito, não é?  
