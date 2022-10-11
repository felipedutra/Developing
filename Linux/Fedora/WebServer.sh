#Preconfigs
useradd felipedutra
usermod -aG wheel felipedutra
passwd felipedutra
su - felipedutra

mkdir ~/.ssh && chmod 700 ~/.ssh

sudo dnf update -y && sudo dnf upgrade -y
sudo dnf -y install vim bash-completion curl wget telnet clang gcc
sudo sestatus
sudo setenforce 0
sudo sed -i 's/^SELINUX=.*/SELINUX=permissive/g' /etc/selinux/config
sudo sed -i 's/^SELINUX=.*/SELINUX=disabled/g' /etc/selinux/config
cat /etc/selinux/config | grep SELINUX=

#installing apache server
sudo dnf -y install httpd
sudo systemctl start httpd
sudo systemctl enable httpd
sudo firewall-cmd --add-service={http,https,samba} --permanent
sudo firewall-cmd --reload
#installing php and MySQL
sudo dnf -y install php  php-cli php-fpm php-mysqlnd php-zip php-devel php-gd php-mcrypt php-mbstring php-curl php-xml php-pear php-bcmath php-json
sudo systemctl restart httpd
sudo hostnamectl set-hostname dutrainc.com.br


curl -s https://checkip.dyndns.org | sed -e 's/.*Current IP Address: //' -e 's/<.*$//'  
