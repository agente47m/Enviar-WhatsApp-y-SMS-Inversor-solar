<h1>Enviar whatsapp y sms cuando no hay red inversor solar</h1>
<h2>Objetivo del proyecto</h2>
<p> El objetivo de este proyecto es tener la posibilidad de enviar una notificación vía WhatsApp o SMS cuando la red del inversor se cae, por lo que esto nos informará que no está .</p>

<h2> Modelos de inversores solares compatibles</h2>
<p> Este proyecto está diseñado al ser compatible con cualquier inversor que utilice el protocolo RS485 RTU.</p>

<p> Uno de los ejemplos de inversores solares compatibles pueden ser: </p>
<li>SALICRU (Equinox 2)</li>
<li>huawei</li>
<li>fronius</li>
<li>victron</li>
<li>Deye</li>

<h2> Hardware necesario para montar este proyecto </h2>
<p> Hemos optado usar hardware fácil de conseguir para montar este proyecto. Todas las placas wue utilizamos estan preesambladas y podéis encontrar en Aliexpress o en Amazon. </p>
<p> A partir de las placas mencionadas anteriormente, hemos diseñado una placa a medida para poder ensamblar todos los componentes integrarlo en una carcasa impresa en 3D para colocarlo en cuadro eléctrico </p>

<p> Lista de materiales necesarios: </p>
<li> ESP32 DEV-KIT V1 30 PINES</li>
<li> Oled ssd1306 (no es obligatorio para que funcione un proyecto, pero es muy recomendable)</li>
<li>TZT SIM800L V2.0.5 MODULO GSM</li>
<li>convertidor TTL to RS485 modelo XY-K485 de la marca diymore</li>
<li> Fuente de alimentación de 3 W marca HI-LINK </li>
<li> PCB a medida (no es obligatorio para que funcione el proyecto)</li>

<p><small> el módulo RS 435 tiene que ser el indicado más arriba, ya que este tiene el control de Bit implementado mediante hardware y no mediante software como son otros módulos más económicos </small></p>

<h2> ensamblado del proyecto </h2>
<p> en este apartado, veremos las particularidades que hay que llevar a cabo Para ensamblar la placa con éxito </p>
<p> la placa se divide en tres partes, la primera capa es donde se sueltan los componentes de potencia AC/DC y los pines de interconexión </p>
<p> la segunda parte hace referencia al ensamblado del procesador. En este caso será un ESP 32 encargado de todo el control del sistema</p>
<p> por ultimo la tercera capa hace referencia a la capa de comunicacion, donde se situa el conversor de TTL a RS485.</p>

----------- Añadir fotografías_-------------
<h2> funcionalidades del proyecto </h2>
<p> aquí veremos la foto dades que tiene este proyecto al día de hoy: </p>
<li> la primera vez que inicia, se genera un web server que te permite escanear las redes del Wi-Fi y escoger la que tú quieras guardandola para posteriormente utilizarla </li>
<li> si la red Wi-Fi guardada desaparece o se cae el sistema se pondrá en modo emparejamiento y generará el web server mencionado anteriormente </li>
<li> si la Wi-Fi está configurada correctamente generará un web server para configurar las direcciones Mob y el teléfono para el envío de WhatsApp y SMS </li>
<li> cuando el inversor deja de recibir corriente de AC EL SISTEMA MANDA UN SMS O WHATSAPP .</li>
<li> actualmente son los capaz de enviar WhatsApp próximamente la versión dos enviará SMS </li>

<p><small> para dar de alta el teléfono de los avisos de WhatsApp revisar el siguiente enlace .</small></p>

<h2> vídeos de demostración</h2>
<p> podemos ver un vídeo de demostración donde se muestra como se configura la red Wi-Fi y como se ve el envío de WhatsApp </p>
 



