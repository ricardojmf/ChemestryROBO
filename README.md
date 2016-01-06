Intruções:

1- Por a pasta chemestry_robotics na pasta src do workspace do ROS

2- Colocar os ficheiros relativos aos robôs que estão na pasta robots no projecto no directorio do stdr_simulator -> /opt/ros/indigo/share/stdr_resources/resources/robots;

3- Colocar os ficheiros relativos ao mapa no directorio que estão na pasta maps no directório do stdr_simulator -> opt/ros/indigo/   	stdr_resources/maps

4- Colocar o ficheiro ch4.sh que está na pasta reactions no directorio do stdr_simulator -> opt/ros/indigo/stdr_resources

5- Abril 4 terminais:

	terminal_1-Correr o comando roslaunch stdr_launchers server_no_map.launch
	terminal_2-Correr os comandos - roscd stdr_resources
					 - rosrun stdr_server load_map maps/game.yaml
					 - ./ch4.sh

	terminal_3-Correr o comando roslaunch stdr_gui stdr_gui.launch
	terminal_4-Correr os comandos -cd <ros_workspace>
				      rosrun chemestry_robotics hydrochloric


João Ribeiro
Jośe Taveira
Ricardo Figueiredo

FEUP @ ROBO 2015



	
 
