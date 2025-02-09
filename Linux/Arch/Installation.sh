loadkeys br-abnt2
ls /sys/firmware/efi/efivars
ping archlinux.org
timedatectl set-ntp true
fdisk -l
fdisk /dev/o_disco_a_ser_particionado
mkfs.ext4 /dev/partição_raiz
mkswap /dev/partição_swap
mount /dev/partição_raiz /mnt
swapon /dev/partição_swap



ls /sys/firmware/efi/efivars
loadkeys br-abnt2
timedatectl set-ntp true
timedatectl status
cfdisk
#sda1 efi 260M
#sda2 root Rest
#sda3 swap 760M
mkfs.ext4 /dev/sda2
mkswap /dev/sda3
mount /dev/sda2 /mnt
swapon /dev/sda3
#Install Arch Linux
pacstrap /mnt base linux linux-firmware
genfstab -U /mnt >> /mnt/etc/fstab
arch-chroot /mnt

#Set the Time Zone
timedatectl set-timezone America/Sao_Paulo
hwclock --systohc
#Set the Locale
pacman -S nano
nano /etc/locale.gen
locale-gen
echo LANG=en_US.UTF-8 > /etc/locale.conf
echo arch > /etc/hostname
echo KEYMAP=br-abnt2 > /etc/vconsole.conf
nano /etc/hosts
        127.0.0.1	localhost
        ::1		localhost
        127.0.1.1	arch
pacman -S dhcpcd
systemctl enable dhcpcd

pacman -S grub efibootmgr dosfstools

mkdir /boot/efi
mkfs.fat -F32 /dev/sda1
mount /dev/sda1 /boot/efi
grub-install --target=x86_64-efi --bootloader-id=GRUB --efi-directory=/boot/efi
grub-mkconfig -o /boot/grub/grub.cfg


useradd felipedutra
usermod -aG wheel felipedutra
passwd felipedutra
passwd



#After Install
sudo pacman -Syyu
sudo pacman -S xorg
sudo pacman -S xfce4 xfce4-goodies
sudo pacman -S lightdm lightdm-gtk-greeter lightdm-gtk-greeter-settings
sudo systemctl enable lightdm
sudo pacman -S base-devel git --needed
cd paru
makepkg -si
sudo pacman -S linux-lts linux-lts-headers














s
