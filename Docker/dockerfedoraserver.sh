#Preconfigs
sudo docker pull fedora
sudo docker run -d --rm -t -p 80:80 --name dutrainc fedora /bin/bash
docker ps
docker exec -it dutrainc bash
docker stop dutrainc
docker start dutrainc

docker pull fedora
docker run --name heisenberg -v ~/Developing/Docker:/workspace -w /workspace -it fedora  /bin/bash




#Install vim etc
dnf install -y  vim bash-completion curl wget telnet
#configuring ssh
dnf install -y openssh-server openssh-clients
systemctl enable sshd
sudo docker inspect -f "{{ .NetworkSettings.IPAddress }}" container_name

#installing apache server
dnf  install -y httpd

systemctl start httpd
systemctl enable httpd
#installing php and MySQL

dnf  install -y php  php-cli php-fpm php-mysqlnd php-zip php-devel php-gd php-mcrypt php-mbstring php-curl php-xml php-pear php-bcmath php-json
systemctl restart httpd





#Running a nginx server:
docker pull nginx
docker run -it --rm -d -p 8080:80 --name web nginx
