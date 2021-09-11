#Preconfigs
sudo dnf -y install vim bash-completion curl wget telnet
sudo sestatus
sudo setenforce 0
sudo sed -i 's/^SELINUX=.*/SELINUX=permissive/g' /etc/selinux/config
sudo sed -i 's/^SELINUX=.*/SELINUX=disabled/g' /etc/selinux/config
cat /etc/selinux/config | grep SELINUX=

#installing apache server
sudo dnf -y install httpd
sudo systemctl start httpd
sudo systemctl enable httpd
sudo firewall-cmd --add-service={http,https} --permanent
sudo firewall-cmd --reload

#installing php and MySQL
sudo dnf install php-cli
sudo dnf -y install php  php-cli php-fpm php-mysqlnd php-zip php-devel php-gd php-mcrypt php-mbstring php-curl php-xml php-pear php-bcmath php-json
sudo systemctl restart httpd
