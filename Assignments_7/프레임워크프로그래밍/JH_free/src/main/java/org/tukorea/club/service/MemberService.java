package org.tukorea.club.service;

import org.tukorea.club.domain.MemberVO;

public interface MemberService {
	public void addMember(MemberVO member) throws Exception;

	public Integer selectMember(MemberVO member) throws Exception;

	public MemberVO readMember(int id) throws Exception;

	public void updateMember(MemberVO member1, MemberVO member2) throws Exception;

	public void deleteMember(int id) throws Exception;
}