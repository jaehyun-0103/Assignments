package org.tukorea.club.service;

import org.tukorea.club.domain.MemberVO;
import org.tukorea.club.persistence.MemberDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

@Service
public class MemberServiceImpl implements MemberService {

	@Autowired
	private MemberDAO memberDAO;

	public void addMember(MemberVO member) throws Exception {
		memberDAO.join(member);
	}

	public Integer selectMember(MemberVO member) throws Exception {
		return memberDAO.login(member);
	}

	public MemberVO readMember(int id) throws Exception {
		return memberDAO.read(id);
	}

	@Transactional ( propagation=Propagation.REQUIRED )
	public void updateMember(MemberVO member1, MemberVO member2) throws Exception {
		memberDAO.update(member1);
		memberDAO.update(member2);
	}

	public void deleteMember(int id) throws Exception {
		memberDAO.delete(id);
	}
}
