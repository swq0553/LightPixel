�}�
  �  1�op\�    ��� �~w�O�h�iyV��%b��S��H�Y��_�B=b��O�@WL*%�������:z���T���0��ں��:XH,W�1n��H}Axs<R� ��E1G��,��XA� z�W�y�HFa�@	��lqTtx={�Lw�:�8������XY���T�AQ�P:�J��Yuqob�p��	���Z	�䆇U��OgSԱ*�2��7!���Ԥ�K$Ke~��^ydܗKPt�6�]����^3>"0@�Zr���)Qv��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l+z�O&����'j��X��-��*vH�R!_���b(y���	�Xx �[H�x8�	�U����}(F��ž��a~��O���o�����ȃ�!ܱ��1X�br7-3$Qvq�d8H�t+�:ԁ�O*��u�#a�&8�5@|��~6,�����1��Z-�]�@�N��d�dۨ� -^�_i{Z��-cF���<R.P��T�pӖN��;�N�̐�>�Z�\�5�ӈ�
r��؊S�<��?�k���J@0����e[)�%�
�Tt�a{�)`��v6w�`�`��
N@gm�����&�f��j�3ԑ0���y����I��3�٫ni�G�D2�S�F��$G+�֥�3ƗVQ�0{{�K�N�AD]ಱ8����D��ږ���/�駿��N��"�˙�x�L=8�6�G�����ԙ��t[���R]�vgS�������A���<<y� �Z +�`�)sH�A���d~�nF�ˊE�1��3kl�(O�}C��Xb�E��-�FM6���Dvm�eȢ	gQ�2{iB�t`��f�]7e���Ú��,�s��[��Kƅ��cA��#jvw��y.-����R��S���D�����7�@m��_�Qx�bANjW:)	��G|(��,Az���Wm��V5=6��D������JD@�٠d��w����O�R(�|�pS����h&����u�"����c�phH��� 5y�;
���<QY0���~��XtH}ƥ�d(< A�X������C�һ�f��(����u��,�mYN�����Y��7>
t0Rs��������Hk��%�ɳFrA:h�`]4�g���r��˲�dv�gyo3y4T?��*.5~DEfK��u,����#V�!��طkIIg<5���/��(Fο��A�9k���jwV�E�%��Z�?�yO��Iv�C���4����v9��b��
��D�}�����?6��^�5k�Hh����N��)�l�(O��~�Ӊ(b[]���G�`
@�!x�_� 	�[��}�� �����o�&�Lq�c��?�=���@�d줪<N+R�t�}>V�9��v���ٍ��m�)7���!���7�KN�k�Uh#���.� L�D)
�p�
��G*~4o�V��	ŝ#�7A�����4�fwq������΁,�-�w=8:�a�Rr�����-8����B6�FaM����s�G�[<۸�
��M%鯁���W��u��'NO.Ы�8i��ʌ����Uw`�)+|�@�R�i,vL��`�AG�j�����_"D�l��-<eqX�z*k�����!ݘ_g����E`*I�HH(�V���H%��ȵ�AU\�g}lP9Y��1(XLS7Ɖ;��D�-��ڳ$msc��4J���g��s�b�e�L=8�6�G�����ԙ��t[���R]�vgS�������A���<<y� �Z +�`�)sH�A���d~�nF�ˊE�1��3k, void* native_wnd)
{
	return std::shared_ptr<Window>(new Window(name, native_wnd));
}

WindowPtr Application::MakeWindow(std::string const & name, int w, int h, bool full_screen)
{
	return std::shared_ptr<Window>(new Window(name, w, h, full_screen));
}

void Application::Update()
{
	this->UpdateStats();
	this->DoUpdate();

	
}

void Application::UpdateStats()
{

}

