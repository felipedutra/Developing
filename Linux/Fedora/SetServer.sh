#Preconfigs
useradd felipedutra
usermod -aG wheel felipedutra
passwd felipedutra
su - felipedutra

mkdir ~/.ssh && chmod 700 ~/.ssh

sudo dnf update -y && sudo dnf upgrade -y
sudo dnf -y install vim bash-completion curl wget telnet clang gcc plexmediaserver onedrive
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
sudo hostnamectl set-hostname heisenberg.com.br

sudo dnf remove docker \
                  docker-client \
                  docker-client-latest \
                  docker-common \
                  docker-latest \
                  docker-latest-logrotate \
                  docker-logrotate \
                  docker-selinux \
                  docker-engine-selinux \
                  docker-engine
sudo dnf -y install dnf-plugins-core
sudo dnf config-manager \
    --add-repo \
    https://download.docker.com/linux/fedora/docker-ce.repo
sudo dnf install docker-ce docker-ce-cli containerd.io
sudo systemctl start docker
sudo systemctl enable docker
sudo docker run hello-world

sudo chown -R felipedutra:felipedutra /mnt/* && sudo chmod -R 777 /mnt/*
sudo dnf install samba
sudo systemctl enable smb --now
sudo smbpasswd -a felipedutra
sudo semanage fcontext --add --type "samba_share_t" ~/
sudo semanage fcontext --add --type "samba_share_t" /mnt/HD/
sudo restorecon -R ~/
sudo restorecon -R /mnt/HD/

sudo nano /etc/samba/smb.conf
[HD]
       	comment = My Share
        path =  /mnt/HD
        writeable = yes
        browseable = yes
        public = yes
        create mask = 0644
        directory mask = 0755
        write list = user
[felipedutra]
     	comment = My Share
        path =  ~/
        writeable = yes
        browseable = yes
        public = yes
        create mask = 0644
        directory mask = 0755
        write list = user


sudo systemctl restart smb
sudo firewall-cmd --add-service={http,https,samba,plex} --permanent
sudo firewall-cmd --reload

sudo dnf upgrade
sudo tee /etc/yum.repos.d/plex.repo<<EOF
[Plexrepo]
name=plexrepo
baseurl=https://downloads.plex.tv/repo/rpm/\$basearch/
enabled=1
gpgkey=https://downloads.plex.tv/plex-keys/PlexSign.key
gpgcheck=1
EOF
sudo dnf install plexmediaserver -y
sudo systemctl start plexmediaserver
sudo systemctl enable plexmediaserver
systemctl status plexmediaserver









sudo reboot


#Convert MKV to MP4
find . -type f -name "*.mkv" -maxdepth 1 \
-exec bash -c 'ffmpeg -i "$0" -vcodec copy -acodec copy "${0/.mkv/.mp4}"' {} \;

find . -type f -name "*.mkv" -maxdepth 3 \
-exec bash -c 'mv ~/' {} \;

find . -type f -name "*.mpg" -maxdepth 1 \
-exec bash -c 'ffmpeg -i "$0" -vcodec copy -acodec copy "${0/.mpg/.mp4}"' {} \;

scp ~/.ssh/id_rsa.pub {username}@{server ip}:~/.ssh/authorized_keys


#To kill a process by name:
ps aux | grep rsync
pkill -f rsync
