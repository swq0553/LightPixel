�}�
  �  x1+�%�    ���~����O��!�l�<`��Ҳ��ނ/��ouT��j���'6�I�4�3�<3L/��^�p�~lG���H���ĝJa�$`D����<�d�O;fr�9�yO��ynA���]��y��A�84	F�*�����;x��Y�%h|�{f�p�zM$��� "qIe��}ֵO�3�m�`]��������#dt�'��}�T;���ks���2H�ۭ�`�(ȁ��u��������%�ڃ�*����}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���l�%�� T8΂.?g�����»�sw2&}�����}�#��� ��4�"���q�^�&c)�#�F�o�|l��5|�dn|�鐣m���j�gH�E�_?D��lb��j��M&���`�k{b���T��ٚ~�O�}�Q"P���4��Q%F<��]��hx�EX�rB���ώaEۓ�jS�t�6P��_ީ{dd��?ֲ���_`�s0Y�49>k,��E'�_"�Ѯb��P���%�9�&���[�B3J��A�����z�c�Zk�˹�����#YũDXW������{�sB��`i��"�|�@"LN��e��>v��p�5�/2����	ਘY���-��X���
q޻Da�'����C
<�Rr���  3	���ݦ����P�׮nSO�?C:���p��ǖMEŉ+��\c,����������c�}���˱)|Z�w�B֭@z�g��-�2�l��`K���|��4�u���כ��Ϭ��� Bind();
	void Release();
	static void Release(Type type);

	uint32_t BufferId() const;
	uint32_t Size() const;

	bool Read(int offset, void *data, int count);
	void Write(int offset, const void *data, int count);

	void Allocate(const void *data, int count);
	void Allocate(int count);

	void *Map(Access access);
	bool unMap();
private:
	Type     mType;
	Usage    mUsage;
	uint32_t mBufferID;
};

