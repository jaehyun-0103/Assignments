package org.tukorea.club.persistence;

import org.tukorea.club.domain.MemberVO;

public interface MemberDAO {
	public void join(MemberVO member) throws Exception;

	public Integer login(MemberVO member) throws Exception;

	public MemberVO read(int id) throws Exception;

	public void update(MemberVO member) throws Exception;

	public void delete(int id) throws Exception;
}