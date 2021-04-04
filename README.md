<h1>Descrição</h1> 

Este projeto tem como objetivo medir a temperatura de um fluido e controlar a temperatura desse fluido.

São necessários para este projeto: 
<ol>
  <li>Um controlador Arduino (utilizei o MEGA, mas pode ser utilizado a maioria das placas);</li>
  <li>3 Resistências elétricas;</li>
  <li>Módulo com no mínimo 3 relés;</li>
  <li>Sensor de temperatura DS18B20;</li>
  <li>Sensor de presença.</li>
</ol>

O código faz a captura das temperaturas enviadas pelo sensor, verifica a diferença com a temperatura desejada(setpoint), e envia informações para os relés ligando e desligando as resistências conforme  valores indicados nos controladores **P,I e D**.

Ele envia duas informações pela porta serial, a temperatura e se foi notado algo pelo sensor de presença, o tratamento desses dados é realizado pelo backend na linguagem node.js, o código para esse arquivo está no link: [Backend](https://www.google.com.br) 
  
  
