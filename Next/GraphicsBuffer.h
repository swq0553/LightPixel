�}�
    �3ep��Y�    ���~�h���O��X�ygH�G�I͸��pF�ް�$R��7F�-o�CC�4p���%�oI{��Oq�b���ufy.�ղ����͈R�28o/�ذI�Y��|��U�V�ܶ�1���O|i�x�~@�O5�3.�I�\�����q�XWR���耘tģ�oC��'!^� � r09ux��7��0*nN�-1��XJ8�+�җщ"я��Y6�50���T����H�/T=����m/��Jk'%/��u��xBĶ�(��2u	�Z?g�M����K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l�$�6k�8��F��f^Y|ل�%՚P�W忢�/u�Tm�V �jo�:K}��|I�l���>a/���☊�e�ܠ
d-Oyssy$r���������v~a�HU9&�f y�&F��Lke�>x.29YM{f���H �nV���&�:N%��|��B���v}`(q��������5����ෘ��i���z�P�]@
HlY�#yB���Z��+�G��U�?>=�4V���� M�A\s��l�Z^�#B�v�.�r`�������%�I����;-��N*8G�:2��!�!�K�i,�2W��M��gB�7������J@0��	Sc��5sOP�aߙ�����������6uMm�C���f�68��CIx@����3�p(_�wM��҃JlԔ/6�ʲD��2:M��=�t3�Z�<����*�!��e���.2ww������U
8������`����r�$S�0gO�:�c�3Ĵ�jd�|�-���z���>Gge() const
		{
			return usage_;
		}

		uint32_t AccessHint() const
		{
			return access_hint_;
		}

		virtual void CopyToBuffer(GraphicsBuffer& rhs) = 0;

	private:
		virtual void DoResize() = 0;

		virtual void* Map(BufferAccess ba) = 0;
		virtual void Unmap() = 0;

	protected:
		BufferUsage usage_;
		uint32_t access_hint_;

		uint32_t size_in_byte_;
		uint32_t hw_buff_size_;
	};
}
#endif
