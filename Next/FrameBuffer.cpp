�}�
    ���K����    ��	�~�v�O�iw)�İ��e{^�oeg�����?�LQ�G`��K�Aȩ7�f{�f�MO0�a�?��'k�S�:Jl�'�G��i�,%�(�D?}�S��婽`�v�P��~ےO��^=��7@;�>"��p���H�c}C��xc��)��L���XN	�E�e���(�R"Ը���Z��
'������>�p=���΅O�1ɵ{��&ʷ���f�1~�O�i�h�H"���I��џ1�BQ��8k�w�֘��:ߖ;�p:�})|b��>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l&����tƉě�'��^�J�i�L1����Q]H!�A"����]��[�*�7�'��/ii�Bޙ��>}����6�D�_�FT)>��B�k_�a6W�%�cܒ���֎��q�Q)u��Q� %7��']��lz?̤����=Y �K��lАg��[�&J*�� &��~xuo6�Qc�!�XH�_Q{}.��mʧQ �˪�����&ٗx�7h�C�-���GN�G04fqg��b���.q�o�v��v�L����B�~r�K�j=��&���[����A�N�Ry0�5Y0�а�i���g*A��Ȅm��yd)so�1[�z�eO��k\���7�?���a'D$ݡ�$����˱���+�)�p�w�����s.S1���K���A|�P{"*9d����J��{���p#�}ʖ���N���?���?^�޻�YY!ag��0ڷ"�����`�6�e�"&��������]���T>P���꯭�1Vt�{��P�r::SetViewport(const ViewportPtr & viewport)
	{
		viewport_ = viewport;
	}

	void FrameBuffer::OnBind()
	{
	
	}

	void FrameBuffer::OnUnbind()
	{

	}

	void FrameBuffer::SwapBuffers()
	{

	}

	void FrameBuffer::Clear(uint32_t flags, const Color & clr, float depth, int32_t stencil)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(clr[0], clr[1], clr[2], clr[3]);
	}

	void FrameBuffer::Discard(uint32_t flags)
	{

	}




}