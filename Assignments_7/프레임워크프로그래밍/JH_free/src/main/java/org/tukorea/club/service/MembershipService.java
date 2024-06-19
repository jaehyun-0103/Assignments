package org.tukorea.club.service;

import org.tukorea.club.domain.MembershipVO;

public interface MembershipService {
	public void addMember(MembershipVO vo) throws Exception;

	public void deleteMember(MembershipVO vo) throws Exception;
}