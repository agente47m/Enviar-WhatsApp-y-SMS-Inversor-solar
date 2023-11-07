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
<br>
<small> el módulo RS 435 tiene que ser el indicado más arriba, ya que este tiene el control de Bit implementado mediante hardware y no mediante software como son otros módulos más económicos </small>

<h2>Ensamblado del proyecto </h2>
<p> En este apartado, veremos las particularidades que hay que llevar a cabo Para ensamblar la placa con éxito </p>
<p> La placa se divide en tres partes, la primera capa es donde se sueltan los componentes de potencia AC/DC y los pines de interconexión </p>
<p> La segunda parte hace referencia al ensamblado del procesador. En este caso será un ESP 32 encargado de todo el control del sistema</p>
<p> Por ultimo la tercera capa hace referencia a la capa de comunicacion, donde se situa el conversor de TTL a RS485.</p>

![IMG_7843](https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/fb89a59a-b281-4f69-a60e-9e56f6d8d8e8)

![IMG_7838](https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/f9d825f1-f3d7-4a1a-b4d2-7f527c002949)

<h2>Funcionalidades del proyecto </h2>
<p> aquí veremos la foto dades que tiene este proyecto al día de hoy: </p>
<li> la primera vez que inicia, se genera un web server que te permite escanear las redes del Wi-Fi y escoger la que tú quieras guardandola para posteriormente utilizarla. CREDENCIALES POR DEFECTO SSID: "AP-4705", CONTRASEÑA:"123456789"</li>
<li> si la red Wi-Fi guardada desaparece o se cae el sistema se pondrá en modo emparejamiento y generará el web server mencionado anteriormente </li>
<li> si la Wi-Fi está configurada correctamente generará un web server para configurar las direcciones Mob y el teléfono para el envío de WhatsApp y SMS </li>
<li> cuando el inversor deja de recibir corriente de AC EL SISTEMA MANDA UN SMS O WHATSAPP .</li>
<li> actualmente son los capaz de enviar WhatsApp próximamente la versión dos enviará SMS </li>
<br>
<small> para dar de alta el teléfono de los avisos de WhatsApp revisar el siguiente enlace .</small>

<h2> Vídeos de demostración</h2>
<p> podemos ver un vídeo de demostración donde se muestra como se configura la red Wi-Fi y como se ve el envío de WhatsApp </p>

<h2>Como funciona</h2>
<p> Cuando encendamos la primera vez nos aparecera un asistente que nos indicara los pasos a seguir para configurar el WIFI</p>

![33](https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/285923ce-b5cf-4745-a79c-19aab454739d)


<img width="899" alt="2" src="https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/a0915350-4226-4d62-858e-07207db4b09a">

<img width="899" alt="3" src="https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/3a777705-937f-4f34-a68f-9fd85528c37e">

<p> Una vez configurado la wifi nos aparecera el estado de conexion con nuestro inversor como de nuestra tarjeta SIM en caso de tenerla conectada</p>

<img width="1036" alt="1" src="https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/44faaae8-4395-4172-b5ac-15a2ac707be2">


![IMG_7850](https://github.com/agente47m/Enviar-WhatsApp-y-SMS-Inversor-solar/assets/14801079/1f99be46-c2bf-4ccb-aff4-08ad1d31dcf6)

<p> Por defecto viene la direccion modbus numero 11015,</p>
<p> Si accedemos a la IP que nos muestra la pantalla se nos abrirar un asistente donde podremos meter el telefono para el aviso como la direccion MODBUS de los HZ de nuestro inversor </p>
<p> 👉 IMPORTANTE! , el numero de telefono tiene que incluir el prefijo por ejemplo en España el "+34"</p>
<p> Una vez configurado esto nuestro dispositivo hara el resto, comprar que el estado de conexion con el inversor sea "OK"</p>
<h2>IMPORTANTE</h2>
<p> Este sistema requiere que el inversor tenga puesta la dirección Mob número tres o cambiarlo en el código antes de subirlo </p>
<p> Este sistema es compatible con otros sistema de monitorizacion ya instalados </p>
<p> Este proyectos utiliza para monitorizar el inverso de vida, que salta una protección diferencial o térmica, tener en cuenta alimentar el equipo en línea diferente del inversor para que cuando se vaya la luz no lo dejes sin servicio. Si se quiere porque salta la protecciones generales es necesario ponerle un sistema Say o una pequeña batería para que se alimente en caso de pérdida de luz </p>


