�}I
    ŢE!H��    ���~�v�O�hg)a� �q�j�s$#s��f��;'yQ�b_8��-��Ǥ�zS��b�l��O�w��\:H�c%s
�)�mcb��z������,�hz��KӮ�g8�����=�\W2(�CĤ'5V+QF��|���r_��F�,5G�ʡA)q0_��)ܢ:I ��ֈ��3�]�"w';�Lř��D�e���<��-}���A!lFާT���`I��6+O�.���ձ�M��{�� ��;��T��vh黋GjR�I��u�h��$��攋4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l�'3T�0A��,P���
��֠�fU�\�����*�����9O����1�8��'.��N�N�B�2���(��l] �Gj�t������j팵&�Q��������"�S[��ǩ�E��x�a�wW����D�͸�^��,�\&.a��{��o�j��	��T�r�d7�Z����E�n��~�o��p� �"T^�!���>�Y��X?z87Շ#�]�B��2�e�395���÷�$��	��`����ޛ����M�䠱D��Pc�A�	~��P\��P���@[�.b�qzʮ�NGę�N!&���}����L��=�ւ���zN���f�÷�����Ǘ��0bfh(*B��?�k�Gs�2���I��6�d�_G�5�\7�0�#G{f�����$�iժ­��ʫ�y��i�Gt���íS�0�hC�k�`��(	2_�(O��>��Wo�v)%��������l~b�l�ō�RI9[��͒F���l�-h���Ú�R�]���>��w	J%�4�b�jF��{����W�{�'W��'�Osz#�3T�y)@�ş��kj�&q7�|�w���熃J�/�j��&&���q��"yP-�:�8�&���FlMm�_����:��N6C~�����n��R����Bzh���?�HglA2��PP\l�Зw%���Į"R�}YХ��Mf�lՉ~w@!���CN�!}������=����5��O��l
R&y��lJ�Emz�Y��j��c�z=�*�U�z &��h�/=+��N�U'δ���2#%"��9��F�*�D���aK,a z6|ۗG�nL�(ɿ
�IrD2x�;G�hz��?g�M��Xh9�
N�B��}�3Y���)�heZ�Sq۳é��_��)�x�J��G�)�M��ڠ����ai�v=�	�w��U|�tjK}�A�����O���"(�%�uU�()f����<D��� �ShҺ���6�Q�I���9<�o��qSQ*���+l"�z�^S�Zs}5W\"����K�!����=ڙG
����7�q�<����XИ�H�8�@��OE	�nvKB��G7s�N�|�t���HK�!����IҼ,�Zd�_��(�X��	�kl)�Ty+0����#����1��0���Y��v�`�����J��/	6���[�%OA�r�k7N�$�LQ��N֐p�$i
���t�K#n��t��x�:3u぀N�/��h�K�B���5VJ+uPR~cOӬ� ���m�����:bq5PB\O���UV(��~X���̘��J�n�^��Q�ȫ����C��C@�����1m'�1��V.�N�3)��q{Z��x���k3	��S\�d���Ԙ�[��m�͔��-*`�W�D|�Wr�� �����G�y������B�JE�Pn
7�K�e��Թ0��*�I`)e h"{<��AT�:��&�}�h�uB	bD�-+n�<iu]3*15���f�����p!��99���Fn��&l�-	>+����6�|I|�k�hC���O�(ͭ�p?�3��Pa7<h�)��	RH�j���}�xhT�p�]����Xh��e�[ �TBI"/jW��q<LU|ry��hg[;���W�D,#���=c�Z$p&�z.�����L�؃#(�-����	��5G}����Y �7�]e�r6��_�b���7�4�ae�f�YC��%��Wz��u<+��Kn6��*�Uf���2����(ɥK�링08+�}��;�~�H?�uw<Yc�*�3N/S���2f!��n�G"�i�:���ԁ�j%�2��!�˘{N=�L�l��/��`��9�j��J&��X�����^�;޷�Zϭ1�Sv�R�x����,�l ]���[ԝ4C�i-8���
;T%Ԉ��L��dg���MiN�Q���@w��̒�{ ?#�*9U�1��	4e$l���9�S'a]Oz�cz�w���"�a�=�JITK�����DJPЧPsSp2r�v�� "�yp�W2uint32_t width, uint32_t height)
	{

	}

	void Application::Update()
	{
		this->UpdateStats();
		this->DoUpdate();

		RendererPtr render = Engine::Instance().RendererInstance();
		render->Refresh();
	
	}

	void Application::UpdateStats()
	{

	}

	void Application::LookAt(const Vec3 &eye, const Vec3 & lookAt, const Vec3 & up)
	{

	}

	void Application::Proj(float nearPlane, float farPlane)
	{

	}

}