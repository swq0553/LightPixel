�}[
    ��0*l�z�    ���~ҩa��O��O��w�A�7�$?�"'SP�u��QgF��ܷD�$C�a�2E�؍����.k��Y��jԝ�)�H��'��ڜn���R(C���Hv���c
�D{*��	�h,�����l2*����n߽e�xqb�J�&����5:X�����},�5�8�`)���l*�%SKDQ�Gi�t���7Ox����1�3)t{��iſ{�{��t��������V�e�����<&�0$b�����[&������ �5a�=+#0�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���wapBuffers();
		bool Ready() const
		{
			return ready_;
		}

		void Ready(bool ready)
		{
			ready_ = ready;
		}
		bool Active()
		{
			return active_;
		}


	private:

		HWND	hWnd_;
		HGLRC	hRC_;
		HDC		hDC_;
		

		bool	ready_;
		bool	active_;
	};
}
#endif

