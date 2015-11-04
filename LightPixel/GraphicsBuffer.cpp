�}�
  �  �FР#��    ��� �~2�o��O��O�g<_,�I�xj��S�C.�mi~����iy<��	�ZKm����q:�=O@s��+��G�D������H�oh��y_�y�z@��^���7׏[V�`A�M� �7î�Bx2#�����ex@�tF5��3��1Hy�ot�s7	phE��#�X�C/g�d}��O-���j֐�fB�o�0�{>$,>.����R��a"�=����Ї,�3m�r���d�^�*���^3>"0@�Zr���)Qv��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l�&5��`D�6�㶙��a��g&��L����KO\��$0!&A.͙�y���%Jm��/�_Qɵ3��(��x*�{���
�W�X*����P��OX&�� ��(�?#+e��ʮ7I�ȕ��^ؽ!�B^J��>	�ONx�#��ߡ04AXY��*Wz��`�Y� `�c����C���������`Xt��z�܄���o�c��oӗ�6�4�3(�V���Y��A�i���t�(�M����F(f|�Ci&���hf>�0Q5���Ɓi])���BNMG���K���#�p���}Ĺ�;8��I�e;����n���e���L�w����	l��"��|Sx����1�-4j_��q�71k�C6��4A�ms*�U��$FM<8;Dmx��د��U���ˈ��ѐ���]��>�14;�F��f+6�E�3RG�x|���|�e)K���H�<��Z�;�����TEy����~�?w��^�ܙ�%v��,�w�|�
зӶ��l�l�.��BM�8����,1.�#4�?b=��R���v��
�H~@ٍ�mcYl����
����σPq���_pU��ZA�7 ��kgl+�Ow��5ܧO�θ;�a]%�_�,G���e}]xB�`vGG������NbW�/�d�c��+�/;e��_�����kI^'a�y��� /�of}%l�����!l<-$n�F� ���Pѯ؜Cz;�3�,���Rm�qxJ�|i��m�;����{��[@�u{g�<��$�Kryd�����*��͞��D������s;��ANB�h���c6������|��ro�º��*���\]۰310cc�j2Jׇ�f(�Uˆ�����1U�ba��xs���8U�׼���&'D��M����|Q�hE�r����F
����I��I����������M�쵶�\X�s�t��+��2<a�l{!�Ǹ��y���q�{��ԧ�zS^��~fC�k2q�	|�_�D��tNG��c�C�Lj$[?G,cŌU#P offset, count, data);
}

void GraphicsBuffer::Allocate(const void *data, int count)
{
	glBufferData(mType, count, data, mUsage);
}

void GraphicsBuffer::Allocate(int count)
{
	Allocate(0, count);
}

void * GraphicsBuffer::Map(Access access)
{
	if (mBufferID)
		return glMapBuffer(mType, access);
	else
		return 0;
}

bool GraphicsBuffer::unMap()
{
	return glUnmapBuffer(mType) == GL_TRUE;
}
