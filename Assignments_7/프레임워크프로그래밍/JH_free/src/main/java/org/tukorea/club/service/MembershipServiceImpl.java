package org.tukorea.club.service;

import org.tukorea.club.domain.MembershipVO;
import org.tukorea.club.persistence.MembershipDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MembershipServiceImpl implements MembershipService {
	@Autowired
	private MembershipDAO membershipDAO;

	public void addMember(MembershipVO vo) throws Exception {
		membershipDAO.add(vo);
	}

	public void deleteMember(MembershipVO vo) throws Exception {
		membershipDAO.delete(vo);
	}
}