UBuntu16.10�°�װftp����
------------------------
### ���ȸ�������Դ����֤Դ�����µģ����������ڱ�֤����ͨ��apt-get install���װftp��
	sudo apt-get update
### ��װvsftp : ʹ��sudo apt-get install vsftp���װvsftp����װ������ҪrootȨ�ޣ�����ʹ��sudo����ʱ��ȡ��
	sudo apt-get install vsftpd
### ��װ��ftp��Ĭ���ǻ��Զ�����ftp�û��ģ�Ȼ����������ftp�û������룬���� sudo passwd ftp��Ȼ���������룬��ȷ�����롣
	sudo passwd ftp
### ����ftp�û��ļ�Ŀ¼��ʹ��sudo mkdir /home/ftp����
	sudo mkdir /home/ftp
### ����ftp��Ŀ¼��Ȩ�ޣ�������Ϊ����ֱ��ʹ�� sudo chmod 777 /home/ftp ���Ȩ������Ϊ777����Ȼ����Ը����Լ�����������á�
	sudo chmod 777 /home/ftp
### ��/etc/vsftpd.conf�����ļ�����һ�����޸ġ�ʹ�� sudo vi /etc/vsftpd.conf�������ļ��������ϲ��vim�༭��Ҳ����ʹ�����򿪡�
	sudo vi /etc/vsftpd.conf
* ��/etc/vsftpd.conf�����ļ��󣬶������ļ������ݽ���һϵ�б�Ҫ���޸ģ�
	* �������ļ��С�anonymous_enable=YES ����Ϊ ��anonymous_enable=NO�����Ƿ���������ftp����������ѡNO��
	* ȡ����������ǰ��ע�ͷ��ţ�
		* local_enable=YES���Ƿ����������û���¼��
		* write_enable=YES���Ƿ����������û�д��Ȩ�ޣ�
		* chroot_local_user=YES���Ƿ������û���������Ŀ¼��
		* chroot_list_enable=YES���Ƿ����������û���������
		* chroot_list_file=/etc/vsftpd.chroot_list�������ļ������ö���˺ţ�
![ftp_02](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_02.png "ftp_02")
![ftp_01](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_01.png "ftp_01")
### Ȼ�󴴽�����chroot_list_file�ļ���·�� �� /etc/vsftpd.chroot_list
	touch /etc/vsftpd.chroot_list
	sudo chmod 777 /etc/vsftpd.chroot_list
Ȼ����/etc/vsftpd.chroot_list�ļ������ftp�û���ftp
![ftp_03](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_03.png "ftp_03")

### ����ftp������һЩ�ļ���/home/ftpĿ¼��
* ����һ���������������ftp://localhost����ҳ��¼��
![ftp_04](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_04.png "ftp_04")
* �����������ն�������ftp localhost��Ȼ�������û���������ʵ�ֵ�¼��
![ftp_05](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_05.png "ftp_05")
![ftp_06](https://github.com/tycao/opencvgit/blob/master/FTP/src/ftp_06.png "ftp_06")


### ����
[������Բο��ٶȾ��飬���������õ�](https://jingyan.baidu.com/article/7908e85c988b23af481ad2ae.html)



	
	
	
ubuntu�°�װvftp ��װvsftpd�󣬵�¼ftp������ʱ������ʾ���� 530 Login incorrect
==================================================