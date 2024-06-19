package org.tukorea.myweb.service;

import java.util.List;

import org.tukorea.myweb.domain.StudentVO;

public interface MemberService {

	public StudentVO readMember(String id) throws Exception;

	public List<StudentVO> readMemberList() throws Exception;

	public void addMember(StudentVO student) throws Exception;

	public void deleteMember(String id) throws Exception;

	public void updateMember(StudentVO student) throws Exception;

}
