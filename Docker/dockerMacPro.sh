docker pull fedora
docker run -d -t --name heinsenberg fedora /bin/bash
docker ps
docker exec -it heinsenberg bash
docker stop heinsenberg
docker start heinsenberg

#On container
dnf update && dnf upgrade
dnf install nginx
sudo dnf -y install vim bash-completion curl wget telnet
sudo dnf -y install php  php-cli php-fpm php-mysqlnd php-zip php-devel php-gd php-mcrypt php-mbstring php-curl php-xml php-pear php-bcmath php-json

sudo dnf -y install httpd
dnf install net-tools
sudo systemctl start httpd
/usr/sbin/httpd
