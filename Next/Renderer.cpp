�}{
    �8#��    ��� �~ʷ}g�O��МVk��"&�A���R$�72�B��� �Y�.�ϩW߅�V6}�[��(����DV��k�g/T9�%�A��\�Dw@N�c!�o��~�h ���C�ɝ/��M�P�N�񴪸��ʫf�G"�w^O����S�}હ��%���>Ms�g=fӣFyi�2��CN'S"S��^�x�c�Z�T���C��m1uy�r/L�1=J	��>	�){��|�bC��SN�&�P�����"0@�Zr���)Qv��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���

	void Renderer::CreateRenderWindow()
	{
		cur_frame_buffer_ = MakeSharedPtr<RenderWindow>();
		screen_frame_buffer_ = cur_frame_buffer_;
		
	}

	const FrameBufferPtr & Renderer::CurFrameBuffer() const
	{
		return cur_frame_buffer_;
	}

	void Renderer::BindFrameBuffer(const FrameBufferPtr & fb)
	{
		cur_frame_buffer_ = fb;
	}

}