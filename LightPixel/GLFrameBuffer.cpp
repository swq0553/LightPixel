�}O
  �  ��+�m�    ��� �~�hm��O�(~�kFw��$�Bm���F9��*dF�+�Qw�����|����k
b_�+2�_y
�T�9k�@��p���KE�s<Y�����b�Jt�tb1A<1<H�p2�G浵au���c��q|rL�|�u��Bty��ѹ���/Î3��Y��.i�P��u�w��oI �ds!�ÒG�ǂ*�����K]�ǘ���I9/@۴��-rh�4�؍���+��y�{6s��B�չ��P1�����)Qv��}f����>B�K�9�xK���}B��4�>w�̝����p��e�5�CJ��<�g�؅�|�p��?8��]Qh2�^ +)�U��G|��e��v{�zp��Y>���᰻��X������b���bBr�Տ��X78�n1Kl$���7#�:27w���#r��+oN&�GE̿T1Y]M�9�5� ��;p��2��`Rֱ�lX�ǉ(M9Y[��,���S�n���id())
// 		{
// 			OGLRenderEngine& re = *checked_cast<OGLRenderEngine*>(&Context::Instance().RenderFactoryInstance().RenderEngineInstance());
// 			re.DeleteFramebuffers(1, &fbo_);
// 		}
		else
		{
			glDeleteFramebuffers(1, &fbo_);
		}
	}
}

void GLFrameBuffer::Clear(uint32_t flags, Color const & clr, float depth, int32_t stencil)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(clr[0], clr[1], clr[2], clr[3]);
}

void GLFrameBuffer::OnBind()
{

}
