UBuntu16.10�°�װftp����
------------------------
## ���ȸ������Դ����֤Դ�����µģ����������ڱ�֤����ͨ��apt-get install���װftp��
	sudo apt-get update
## ��װvsftp : ʹ��sudo apt-get install vsftp���װvsftp����װ�����ҪrootȨ�ޣ�����ʹ��sudo����ʱ��ȡ��
	sudo apt-get install vsftpd
## ��װ��ftp��Ĭ���ǻ��Զ�����ftp�û��ģ�Ȼ����������ftp�û������룬���� sudo passwd ftp��Ȼ���������룬��ȷ�����롣
	sudo passwd ftp
## ����ftp�û��ļ�Ŀ¼��ʹ��sudo mkdir /home/ftp����
	sudo mkdir /home/ftp
## ����ftp��Ŀ¼��Ȩ�ޣ�������Ϊ����ֱ��ʹ�� sudo chmod 777 /home/ftp ���Ȩ������Ϊ777����Ȼ����Ը����Լ�����������á�
	sudo chmod 777 /home/ftp
## ��/etc/vsftpd.conf�����ļ�����һ�����޸ġ�ʹ�� sudo vi /etc/vsftpd.conf�������ļ��������ϲ��vim�༭��Ҳ����ʹ�����򿪡�
	sudo vi /etc/vsftpd.conf
* ��/etc/vsftpd.conf�����ļ��󣬶������ļ������ݽ���һϵ�б�Ҫ���޸�
** �������ļ��С�anonymous_enable=YES ����Ϊ ��anonymous_enable=NO�����Ƿ���������ftp����������ѡNO��
** ȡ����������ǰ��ע�ͷ��ţ�
	local_enable=YES���Ƿ��������û���¼��
	write_enable=YES���Ƿ��������û�д��Ȩ�ޣ�
	chroot_local_user=YES���Ƿ������û���������Ŀ¼��
	chroot_list_enable=YES���Ƿ����������û���������
	chroot_list_file=/etc/vsftpd.chroot_list�������ļ������ö���˺ţ�
![](ftp_02)
![](ftp_01)
## Ȼ�󴴽�����chroot_list_file�ļ���·�� �� /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
Ȼ����/etc/vsftpd.chroot_list�ļ�����ftp�û���ftp

	
	
	
���������µķ����޸�/etc/vsftpd.conf�����ļ������ݣ�
==================================================
